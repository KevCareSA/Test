#!/usr/bin/python3

"""
Test module for user.py and the User class
"""


import unittest
from time import sleep
import os
from models.engine.file_storage import FileStorage
from datetime import datetime
import models.user as usermodule
from models.base_model import BaseModel
from models.user import User


class Test_US_Doc(unittest.TestCase):
    """Tests for User class Documentation"""
    def test_module_doc(self):
        """tests User module documentation"""
        self.assertGreaterEqual(len(usermodule.__doc__), 1)

    def test_class_doc(self):
        """Test User class documentation"""
        self.assertGreaterEqual(len(User.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreaterEqual(len(User.__init__.__doc__), 1)
        self.assertGreaterEqual(len(User.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreaterEqual(len(User.save.__doc__), 1)
        self.assertGreaterEqual(len(User.to_dict.__doc__), 1)


class Test_US_Instantiation(unittest.TestCase):
    """Test User instantiation"""

    def test_User_multiple_args(self):
        """Test User with excess args"""
        ct = User(1, 2, 3, 4, 5, "hey", "hello", 9.0, [1, 2, 3])
        self.assertTrue(ct is ct)

    def test_inheritance(self):
        ct = User()
        self.assertIsInstance(ct, BaseModel)
        self.assertTrue(issubclass(User, BaseModel))

    def test_instance(self):
        """Test instance of User class"""
        ct = User()
        self.assertEqual(type(ct), User)
        self.assertTrue(issubclass(type(ct), User))
        self.assertTrue(isinstance(ct, User))

    def test_mandatory_attributes(self):
        """tests most basic attributes"""
        ct = User()
        self.assertTrue(hasattr(ct, "created_at"))
        self.assertTrue(hasattr(ct, "updated_at"))
        self.assertTrue(hasattr(ct, "id"))
        self.assertTrue(hasattr(ct, "first_name"))
        self.assertTrue(hasattr(ct, "last_name"))
        self.assertTrue(hasattr(ct, "email"))
        self.assertTrue(hasattr(ct, "password"))

    def test_extra_attribute_types(self):
        """Tests the data types of attributes that are not Inherited"""
        self.assertEqual(type(User.email), str)
        self.assertEqual(type(User.password), str)
        self.assertEqual(type(User.first_name), str)
        self.assertEqual(type(User.last_name), str)

    def test_type_initialization(self):
        """Tests for initialization value of public attributes"""
        self.assertEqual(User.email, "")
        self.assertEqual(User.password, "")
        self.assertEqual(User.first_name, "")
        self.assertEqual(User.last_name, "")

    def test_time_datatype(self):
        """Test the type of created_at and updated_at"""
        ct = User()
        self.assertEqual(type(ct.created_at), datetime)
        self.assertEqual(type(ct.updated_at), datetime)

    def test_id_datatype(self):
        """Test the type of the object id"""
        ct = User()
        self.assertEqual(type(ct.id), str)

    def test_uuid4_id(self):
        """tests if id is of type uuid4"""
        ct = User()
        objlist = [User() for _ in range(10)]
        for obj in objlist:
            self.assertEqual(len(obj.id), len(ct.id))
            self.assertEqual(obj.id[14], '4')

    def test_creation_time(self):
        """Test instance of User class"""
        ct = User()
        difference = ct.updated_at - ct.created_at
        sleep(0.0001)
        ct2 = User()
        self.assertLess(abs(difference.total_seconds()), 0.01)
        self.assertGreater(ct2.created_at, ct.created_at)
        self.assertGreater(ct2.updated_at, ct.updated_at)

    def test_id_equivalence(self):
        """Tests to see if 2 id's are equivalent in value"""
        ct1 = User()
        ct2 = User()
        self.assertNotEqual(ct1.id, ct2.id)

    def test_objstr(self):
        """tests objects strings"""
        ct = User()
        expected = f"[User] ({ct.id}) {ct.__dict__}"
        self.assertEqual(str(ct), expected)

    def test_to_dict_type(self):
        """Tests the return type of to dict"""
        ct = User()
        self.assertEqual(type(ct.to_dict()), dict)

    def test_to_dict_with_args(self):
        """tests to_dict with args"""
        with self.assertRaises(TypeError):
            User.to_dict(self, 1234)

    def test_dictattr(self):
        """Funtion tests if dictionary attributes is accurate"""
        ct = User()
        ct.aliases = "Tom Marvolo Riddle"
        ct.age = 52
        b_dict = ct.to_dict()
        self.assertEqual(b_dict['__class__'], "User")
        self.assertEqual(b_dict['created_at'], ct.created_at.isoformat())
        self.assertEqual(b_dict['updated_at'], ct.updated_at.isoformat())
        self.assertEqual(b_dict['id'], ct.id)
        self.assertEqual(b_dict['aliases'], "Tom Marvolo Riddle")
        self.assertEqual(b_dict['age'], 52)

    def test_newobj_from_dict(self):
        """Testing creating a new object from"""
        ct = User()
        ct2 = User(**ct.to_dict())
        self.assertEqual(ct.created_at, ct2.created_at)
        self.assertEqual(ct.updated_at, ct2.updated_at)
        self.assertEqual(ct.id, ct2.id)
        self.assertFalse(ct is ct2)


class Test_Serialization(unittest.TestCase):
    """Test object serialization and deserialization"""

    def tearDown(self):
        if os.path.exists(FileStorage._FileStorage__file_path):
            os.remove(FileStorage._FileStorage__file_path)

    def test_save_with_args(self):
        """Test if object is saved with multiple args"""
        with self.assertRaises(TypeError):
            User.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        ct = User()
        ct.phonenum = "078 555 7832"
        ct.income = 100100
        ct.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))
        if os.path.exists(FileStorage._FileStorage__file_path):
            with open(FileStorage._FileStorage__file_path, "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)
                self.assertTrue(f'"User.{ct.id}"' in contents)
                self.assertTrue(f'"{ct.updated_at.isoformat()}"' in contents)
                self.assertTrue(f'"{ct.created_at.isoformat()}"' in contents)
                self.assertTrue('100100' in contents)
                self.assertTrue('"078 555 7832"' in contents)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        ct = User()
        initial_time = ct.updated_at
        ct.save()
        time_after_save = ct.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
