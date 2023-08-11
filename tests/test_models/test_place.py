#!/usr/bin/python3

"""
Test module for place.py and the Place class
"""


import unittest
from time import sleep
import os
from datetime import datetime
import models.place as placemodule
from models.base_model import BaseModel
from models.place import Place


class Test_PL_Doc(unittest.TestCase):
    """Tests for Place class Documentation"""
    def test_module_doc(self):
        """tests Place module documentation"""
        self.assertGreaterEqual(len(placemodule.__doc__), 1)

    def test_class_doc(self):
        """Test Place class documentation"""
        self.assertGreaterEqual(len(Place.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreaterEqual(len(Place.__init__.__doc__), 1)
        self.assertGreaterEqual(len(Place.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreaterEqual(len(Place.save.__doc__), 1)
        self.assertGreaterEqual(len(Place.to_dict.__doc__), 1)


class Test_PL_Instantiation(unittest.TestCase):
    """Test Place instantiation"""

    def test_Place_multiple_args(self):
        """Test Place with excess args"""
        ct = Place(1, 2, 3, 4, 5, "hey", "hello", 9.0, [1, 2, 3])
        self.assertTrue(ct is ct)

    def test_inheritance(self):
        ct = Place()
        self.assertIsInstance(ct, BaseModel)
        self.assertTrue(issubclass(Place, BaseModel))

    def test_instance(self):
        """Test instance of Place class"""
        ct = Place()
        self.assertEqual(type(ct), Place)
        self.assertTrue(issubclass(type(ct), Place))
        self.assertTrue(isinstance(ct, Place))

    def test_mandatory_attributes(self):
        """tests most basic attributes"""
        ct = Place()
        self.assertTrue(hasattr(ct, "created_at"))
        self.assertTrue(hasattr(ct, "updated_at"))
        self.assertTrue(hasattr(ct, "id"))

    def test_time_datatype(self):
        """Test the type of created_at and updated_at"""
        ct = Place()
        self.assertEqual(type(ct.created_at), datetime)
        self.assertEqual(type(ct.updated_at), datetime)

    def test_id_datatype(self):
        """Test the type of the object id"""
        ct = Place()
        self.assertEqual(type(ct.id), str)

    def test_uuid4_id(self):
        """tests if id is of type uuid4"""
        ct = Place()
        objlist = [Place() for _ in range(10)]
        for obj in objlist:
            self.assertEqual(len(obj.id), len(ct.id))
            self.assertEqual(obj.id[14], '4')

    def test_creation_time(self):
        """Test instance of Place class"""
        ct = Place()
        difference = ct.updated_at - ct.created_at
        sleep(0.0001)
        ct2 = Place()
        self.assertLess(abs(difference.total_seconds()), 0.01)
        self.assertGreater(ct2.created_at, ct.created_at)
        self.assertGreater(ct2.updated_at, ct.updated_at)

    def test_id_equivalence(self):
        """Tests to see if 2 id's are equivalent in value"""
        ct1 = Place()
        ct2 = Place()
        self.assertNotEqual(ct1.id, ct2.id)

    def test_objstr(self):
        """tests objects strings"""
        ct = Place()
        expected = f"[Place] ({ct.id}) {ct.__dict__}"
        self.assertEqual(str(ct), expected)

    def test_to_dict_type(self):
        """Tests the return type of to dict"""
        ct = Place()
        self.assertEqual(type(ct.to_dict()), dict)

    def test_to_dict_with_args(self):
        """tests to_dict with args"""
        with self.assertRaises(TypeError):
            Place.to_dict(self, 1234)

    def test_dictattr(self):
        """Funtion tests if dictionary attributes is accurate"""
        ct = Place()
        ct.aliases = "Tom Marvolo Riddle"
        ct.age = 52
        b_dict = ct.to_dict()
        self.assertEqual(b_dict['__class__'], "Place")
        self.assertEqual(b_dict['created_at'], ct.created_at.isoformat())
        self.assertEqual(b_dict['updated_at'], ct.updated_at.isoformat())
        self.assertEqual(b_dict['id'], ct.id)
        self.assertEqual(b_dict['aliases'], "Tom Marvolo Riddle")
        self.assertEqual(b_dict['age'], 52)

    def test_newobj_from_dict(self):
        """Testing creating a new object from"""
        ct = Place()
        ct2 = Place(**ct.to_dict())
        self.assertEqual(ct.created_at, ct2.created_at)
        self.assertEqual(ct.updated_at, ct2.updated_at)
        self.assertEqual(ct.id, ct2.id)
        self.assertFalse(ct is ct2)


class Test_Serialization(unittest.TestCase):
    """Test object serialization and deserialization"""

    def tearDown(self):
        if os.path.exists("file.json"):
            os.remove("file.json")

    def test_save_with_args(self):
        """Test if object is saved with multiple args"""
        with self.assertRaises(TypeError):
            Place.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        ct = Place()
        ct.save()
        self.assertTrue(os.path.exists("file.json"))
        if os.path.exists("file.json"):
            with open("file.json", "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        ct = Place()
        initial_time = ct.updated_at
        ct.save()
        time_after_save = ct.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
