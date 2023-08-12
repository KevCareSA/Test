#!/usr/bin/python3

"""
Test module for city.py and the City class
"""


import unittest
from time import sleep
import os
from models.engine.file_storage import FileStorage
from datetime import datetime
import models.city as citymodule
from models.base_model import BaseModel
from models.city import City


class Test_CT_Doc(unittest.TestCase):
    """Tests for City class Documentation"""
    def test_module_doc(self):
        """tests City module documentation"""
        self.assertGreaterEqual(len(citymodule.__doc__), 1)

    def test_class_doc(self):
        """Test City class documentation"""
        self.assertGreaterEqual(len(City.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreaterEqual(len(City.__init__.__doc__), 1)
        self.assertGreaterEqual(len(City.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreaterEqual(len(City.save.__doc__), 1)
        self.assertGreaterEqual(len(City.to_dict.__doc__), 1)


class Test_CT_Instantiation(unittest.TestCase):
    """Test City instantiation"""

    def test_City_multiple_args(self):
        """Test City with excess args"""
        ct = City(1, 2, 3, 4, 5, "hey", "hello", 9.0, [1, 2, 3])
        self.assertTrue(ct is ct)

    def test_inheritance(self):
        ct = City()
        self.assertIsInstance(ct, BaseModel)
        self.assertTrue(issubclass(City, BaseModel))

    def test_instance(self):
        """Test instance of City class"""
        ct = City()
        self.assertEqual(type(ct), City)
        self.assertTrue(issubclass(type(ct), City))
        self.assertTrue(isinstance(ct, City))

    def test_mandatory_attributes(self):
        """tests existence of default attributes"""
        ct = City()
        self.assertTrue(hasattr(ct, "created_at"))
        self.assertTrue(hasattr(ct, "updated_at"))
        self.assertTrue(hasattr(ct, "id"))
        self.assertTrue(hasattr(ct, "name"))
        self.assertTrue(hasattr(ct, "state_id"))

    def test_extra_attribute_types(self):
        """Tests types of attributes not inherited from BaseModel"""
        self.assertEqual(type(City.name), str)
        self.assertEqual(type(City.state_id), str)

    def test_type_initialization(self):
        """Tests initialization value of public attributes"""
        self.assertEqual(City.name, "")
        self.assertEqual(City.state_id, "")

    def test_time_datatype(self):
        """Test the type of created_at and updated_at"""
        ct = City()
        self.assertEqual(type(ct.created_at), datetime)
        self.assertEqual(type(ct.updated_at), datetime)

    def test_id_datatype(self):
        """Test the type of object id"""
        ct = City()
        self.assertEqual(type(ct.id), str)

    def test_uuid4_id(self):
        """tests if id is of type uuid4"""
        ct = City()
        objlist = [City() for _ in range(10)]
        for obj in objlist:
            self.assertEqual(len(obj.id), len(ct.id))
            self.assertEqual(obj.id[14], '4')

    def test_creation_time(self):
        """Test instance of City class"""
        ct = City()
        difference = ct.updated_at - ct.created_at
        sleep(0.0001)
        ct2 = City()
        self.assertLess(abs(difference.total_seconds()), 0.01)
        self.assertGreater(ct2.created_at, ct.created_at)
        self.assertGreater(ct2.updated_at, ct.updated_at)

    def test_id_equivalence(self):
        """Tests to see if 2 id's are equivalent in value"""
        ct1 = City()
        ct2 = City()
        self.assertNotEqual(ct1.id, ct2.id)

    def test_objstr(self):
        """tests objects strings"""
        ct = City()
        expected = f"[City] ({ct.id}) {ct.__dict__}"
        self.assertEqual(str(ct), expected)

    def test_to_dict_type(self):
        """Tests the return type of to dict"""
        ct = City()
        self.assertEqual(type(ct.to_dict()), dict)

    def test_to_dict_with_args(self):
        """tests to_dict with args"""
        with self.assertRaises(TypeError):
            City.to_dict(self, 1234)

    def test_dictattr(self):
        """Funtion tests if dictionary attributes is accurate"""
        ct = City()
        ct.aliases = "Tom Marvolo Riddle"
        ct.age = 52
        b_dict = ct.to_dict()
        self.assertEqual(b_dict['__class__'], "City")
        self.assertEqual(b_dict['created_at'], ct.created_at.isoformat())
        self.assertEqual(b_dict['updated_at'], ct.updated_at.isoformat())
        self.assertEqual(b_dict['id'], ct.id)
        self.assertEqual(b_dict['aliases'], "Tom Marvolo Riddle")
        self.assertEqual(b_dict['age'], 52)

    def test_newobj_from_dict(self):
        """Testing creating a new object from a dictionary"""
        ct = City()
        ct2 = City(**ct.to_dict())
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
            City.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        ct = City()
        ct.phonenum = "078 555 7832"
        ct.income = 100100
        ct.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))
        if os.path.exists(FileStorage._FileStorage__file_path):
            with open(FileStorage._FileStorage__file_path, "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)
                self.assertTrue(f'"City.{ct.id}"' in contents)
                self.assertTrue(f'"{ct.updated_at.isoformat()}"' in contents)
                self.assertTrue(f'"{ct.created_at.isoformat()}"' in contents)
                self.assertTrue('100100' in contents)
                self.assertTrue('"078 555 7832"' in contents)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        ct = City()
        initial_time = ct.updated_at
        ct.save()
        time_after_save = ct.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
