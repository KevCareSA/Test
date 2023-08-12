#!/usr/bin/python3

"""
Test module for review.py and the Review class
"""


import unittest
from time import sleep
import os
from models.engine.file_storage import FileStorage
from datetime import datetime
import models.review as reviewmodule
from models.base_model import BaseModel
from models.review import Review


class Test_RE_Doc(unittest.TestCase):
    """Tests for Review class Documentation"""
    def test_module_doc(self):
        """tests Review module documentation"""
        self.assertGreaterEqual(len(reviewmodule.__doc__), 1)

    def test_class_doc(self):
        """Test Review class documentation"""
        self.assertGreaterEqual(len(Review.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreaterEqual(len(Review.__init__.__doc__), 1)
        self.assertGreaterEqual(len(Review.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreaterEqual(len(Review.save.__doc__), 1)
        self.assertGreaterEqual(len(Review.to_dict.__doc__), 1)


class Test_RE_Instantiation(unittest.TestCase):
    """Test Review instantiation"""

    def test_Review_multiple_args(self):
        """Test Review with excess args"""
        ct = Review(1, 2, 3, 4, 5, "hey", "hello", 9.0, [1, 2, 3])
        self.assertTrue(ct is ct)

    def test_inheritance(self):
        ct = Review()
        self.assertIsInstance(ct, BaseModel)
        self.assertTrue(issubclass(Review, BaseModel))

    def test_instance(self):
        """Test instance of Review class"""
        ct = Review()
        self.assertEqual(type(ct), Review)
        self.assertTrue(issubclass(type(ct), Review))
        self.assertTrue(isinstance(ct, Review))

    def test_mandatory_attributes(self):
        """tests most basic attributes"""
        ct = Review()
        self.assertTrue(hasattr(ct, "created_at"))
        self.assertTrue(hasattr(ct, "updated_at"))
        self.assertTrue(hasattr(ct, "id"))
        self.assertTrue(hasattr(ct, "text"))
        self.assertTrue(hasattr(ct, "user_id"))
        self.assertTrue(hasattr(ct, "place_id"))

    def test_extra_attribute_types(self):
        """Tests the data types of attributes that are not Inherited"""
        self.assertEqual(type(Review.text), str)
        self.assertEqual(type(Review.user_id), str)
        self.assertEqual(type(Review.place_id), str)

    def test_type_initialization(self):
        """Tests the initialzation value of public attributes"""
        self.assertEqual(Review.text, "")
        self.assertEqual(Review.user_id, "")
        self.assertEqual(Review.place_id, "")

    def test_time_datatype(self):
        """Test the type of created_at and updated_at"""
        ct = Review()
        self.assertEqual(type(ct.created_at), datetime)
        self.assertEqual(type(ct.updated_at), datetime)

    def test_id_datatype(self):
        """Test the type of the object id"""
        ct = Review()
        self.assertEqual(type(ct.id), str)

    def test_uuid4_id(self):
        """tests if id is of type uuid4"""
        ct = Review()
        objlist = [Review() for _ in range(10)]
        for obj in objlist:
            self.assertEqual(len(obj.id), len(ct.id))
            self.assertEqual(obj.id[14], '4')

    def test_creation_time(self):
        """Test instance of Review class"""
        ct = Review()
        difference = ct.updated_at - ct.created_at
        sleep(0.0001)
        ct2 = Review()
        self.assertLess(abs(difference.total_seconds()), 0.01)
        self.assertGreater(ct2.created_at, ct.created_at)
        self.assertGreater(ct2.updated_at, ct.updated_at)

    def test_id_equivalence(self):
        """Tests to see if 2 id's are equivalent in value"""
        ct1 = Review()
        ct2 = Review()
        self.assertNotEqual(ct1.id, ct2.id)

    def test_objstr(self):
        """tests objects strings"""
        ct = Review()
        expected = f"[Review] ({ct.id}) {ct.__dict__}"
        self.assertEqual(str(ct), expected)

    def test_to_dict_type(self):
        """Tests the return type of to dict"""
        ct = Review()
        self.assertEqual(type(ct.to_dict()), dict)

    def test_to_dict_with_args(self):
        """tests to_dict with args"""
        with self.assertRaises(TypeError):
            Review.to_dict(self, 1234)

    def test_dictattr(self):
        """Funtion tests if dictionary attributes is accurate"""
        ct = Review()
        ct.aliases = "Tom Marvolo Riddle"
        ct.age = 52
        b_dict = ct.to_dict()
        self.assertEqual(b_dict['__class__'], "Review")
        self.assertEqual(b_dict['created_at'], ct.created_at.isoformat())
        self.assertEqual(b_dict['updated_at'], ct.updated_at.isoformat())
        self.assertEqual(b_dict['id'], ct.id)
        self.assertEqual(b_dict['aliases'], "Tom Marvolo Riddle")
        self.assertEqual(b_dict['age'], 52)

    def test_newobj_from_dict(self):
        """Testing creating a new object from"""
        ct = Review()
        ct2 = Review(**ct.to_dict())
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
            Review.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        ct = Review()
        ct.phonenum = "078 555 7832"
        ct.income = 100100
        ct.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))
        if os.path.exists(FileStorage._FileStorage__file_path):
            with open(FileStorage._FileStorage__file_path, "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)
                self.assertTrue(f'"Review.{ct.id}"' in contents)
                self.assertTrue(f'"{ct.updated_at.isoformat()}"' in contents)
                self.assertTrue(f'"{ct.created_at.isoformat()}"' in contents)
                self.assertTrue('100100' in contents)
                self.assertTrue('"078 555 7832"' in contents)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        ct = Review()
        initial_time = ct.updated_at
        ct.save()
        time_after_save = ct.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
