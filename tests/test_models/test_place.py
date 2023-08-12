#!/usr/bin/python3

"""
Test module for place.py and the Place class
"""


import unittest
from time import sleep
import os
from models.engine.file_storage import FileStorage
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
        self.assertTrue(hasattr(ct, "name"))
        self.assertTrue(hasattr(ct, "city_id"))
        self.assertTrue(hasattr(ct, "user_id"))
        self.assertTrue(hasattr(ct, "description"))
        self.assertTrue(hasattr(ct, "number_rooms"))
        self.assertTrue(hasattr(ct, "number_bathrooms"))
        self.assertTrue(hasattr(ct, "max_guest"))
        self.assertTrue(hasattr(ct, "price_by_night"))
        self.assertTrue(hasattr(ct, "latitude"))
        self.assertTrue(hasattr(ct, "longitude"))
        self.assertTrue(hasattr(ct, "amenity_ids"))

    def test_extra_attribute_types(self):
        """Tests the data types of attributes that are not Inherited"""
        self.assertEqual(type(Place.name), str)
        self.assertEqual(type(Place.city_id), str)
        self.assertEqual(type(Place.user_id), str)
        self.assertEqual(type(Place.description), str)
        self.assertEqual(type(Place.number_rooms), int)
        self.assertEqual(type(Place.number_bathrooms), int)
        self.assertEqual(type(Place.max_guest), int)
        self.assertEqual(type(Place.price_by_night), int)
        self.assertEqual(type(Place.latitude), float)
        self.assertEqual(type(Place.longitude), float)
        self.assertEqual(type(Place.amenity_ids), list)

    def test_type_initialization(self):
        """Tests the initialization value of public attributes"""
        self.assertEqual(Place.name, "")
        self.assertEqual(Place.city_id, "")
        self.assertEqual(Place.user_id, "")
        self.assertEqual(Place.description, "")
        self.assertEqual(Place.number_rooms, 0)
        self.assertEqual(Place.number_bathrooms, 0)
        self.assertEqual(Place.max_guest, 0)
        self.assertEqual(Place.price_by_night, 0)
        self.assertEqual(Place.latitude, 0.0)
        self.assertEqual(Place.longitude, 0.0)
        self.assertEqual(Place.amenity_ids, [])

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
        if os.path.exists(FileStorage._FileStorage__file_path):
            os.remove(FileStorage._FileStorage__file_path)

    def test_save_with_args(self):
        """Test if object is saved with multiple args"""
        with self.assertRaises(TypeError):
            Place.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        ct = Place()
        ct.phonenum = "078 555 7832"
        ct.income = 100100
        ct.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))
        if os.path.exists(FileStorage._FileStorage__file_path):
            with open(FileStorage._FileStorage__file_path, "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)
                self.assertTrue(f'"Place.{ct.id}"' in contents)
                self.assertTrue(f'"{ct.updated_at.isoformat()}"' in contents)
                self.assertTrue(f'"{ct.created_at.isoformat()}"' in contents)
                self.assertTrue('100100' in contents)
                self.assertTrue('"078 555 7832"' in contents)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        ct = Place()
        initial_time = ct.updated_at
        ct.save()
        time_after_save = ct.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
