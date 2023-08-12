#!/usr/bin/python3

"""
Test module for base_model.py and the BaseModel class
"""

import unittest
from models.engine.file_storage import FileStorage
from time import sleep
import os
from datetime import datetime
import models.base_model as bm_module
from models.base_model import BaseModel


class Test_BM_Doc(unittest.TestCase):
    """Tests for BaseModel class Documentation"""
    def test_module_doc(self):
        """tests BaseModel module documentation"""
        self.assertGreaterEqual(len(bm_module.__doc__), 1)

    def test_class_doc(self):
        """Test BaseModel class documentation"""
        self.assertGreaterEqual(len(BaseModel.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreaterEqual(len(BaseModel.__init__.__doc__), 1)
        self.assertGreaterEqual(len(BaseModel.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreaterEqual(len(BaseModel.save.__doc__), 1)
        self.assertGreaterEqual(len(BaseModel.to_dict.__doc__), 1)


class Test_BM_Instantiation(unittest.TestCase):
    """Test BaseModel instantiation"""

    def test_BaseModel_multiple_args(self):
        """Test BaseModel with excess args"""
        base = BaseModel(1, 2, 3, 4, 5, "hey", "hello", 9.0, [1, 2, 3])
        self.assertTrue(base is base)

    def test_instance(self):
        """Test instance of BaseModel class"""
        base = BaseModel()
        self.assertEqual(type(base), BaseModel)
        self.assertTrue(issubclass(type(base), BaseModel))
        self.assertTrue(isinstance(base, BaseModel))

    def test_mandatory_attributes(self):
        """tests most basic attributes"""
        base = BaseModel()
        self.assertTrue(hasattr(base, "created_at"))
        self.assertTrue(hasattr(base, "updated_at"))
        self.assertTrue(hasattr(base, "id"))

    def test_time_datatype(self):
        """Test the type of created_at and updated_at"""
        base = BaseModel()
        self.assertEqual(type(base.created_at), datetime)
        self.assertEqual(type(base.updated_at), datetime)

    def test_id_datatype(self):
        """Test the type of the object id"""
        base = BaseModel()
        self.assertEqual(type(base.id), str)

    def test_uuid4_id(self):
        """tests if id is of type uuid4"""
        base = BaseModel()
        objlist = [BaseModel() for _ in range(10)]
        for obj in objlist:
            self.assertEqual(len(obj.id), len(base.id))
            self.assertEqual(obj.id[14], '4')

    def test_creation_time(self):
        """Test instance of BaseModel class"""
        base = BaseModel()
        difference = base.updated_at - base.created_at
        sleep(0.0001)
        base2 = BaseModel()
        self.assertLess(abs(difference.total_seconds()), 0.01)
        self.assertGreater(base2.created_at, base.created_at)
        self.assertGreater(base2.updated_at, base.updated_at)

    def test_id_equivalence(self):
        """Tests to see if 2 id's are equivalent in value"""
        base1 = BaseModel()
        base2 = BaseModel()
        self.assertNotEqual(base1.id, base2.id)

    def test_objstr(self):
        """tests objects strings"""
        base = BaseModel()
        expected = f"[BaseModel] ({base.id}) {base.__dict__}"
        self.assertEqual(str(base), expected)

    def test_to_dict_type(self):
        """Tests the return type of to dict"""
        base = BaseModel()
        self.assertEqual(type(base.to_dict()), dict)

    def test_to_dict_with_args(self):
        """tests to_dict with args"""
        with self.assertRaises(TypeError):
            BaseModel.to_dict(self, 1234)

    def test_dictattr(self):
        """Funtion tests if dictionary attributes is accurate"""
        base = BaseModel()
        base.aliases = "Tom Marvolo Riddle"
        base.age = 52
        b_dict = base.to_dict()
        self.assertEqual(b_dict['__class__'], "BaseModel")
        self.assertEqual(b_dict['created_at'], base.created_at.isoformat())
        self.assertEqual(b_dict['updated_at'], base.updated_at.isoformat())
        self.assertEqual(b_dict['id'], base.id)
        self.assertEqual(b_dict['aliases'], "Tom Marvolo Riddle")
        self.assertEqual(b_dict['age'], 52)

    def test_newobj_from_dict(self):
        """Testing creating a new object from"""
        base = BaseModel()
        base2 = BaseModel(**base.to_dict())
        self.assertEqual(base.created_at, base2.created_at)
        self.assertEqual(base.updated_at, base2.updated_at)
        self.assertEqual(base.id, base2.id)
        self.assertFalse(base is base2)


class Test_Serialization(unittest.TestCase):
    """Test object serialization and deserialization"""

    def tearDown(self):
        if os.path.exists(FileStorage._FileStorage__file_path):
            os.remove(FileStorage._FileStorage__file_path)

    def test_save_with_args(self):
        """Test if object is saved with multiple args"""
        with self.assertRaises(TypeError):
            BaseModel.save(self, 1234)

    def test_save_contents(self):
        """Test if file is saved to the right contents"""
        base = BaseModel()
        base.phonenum = "078 555 7832"
        base.income = 100100
        base.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))
        if os.path.exists(FileStorage._FileStorage__file_path):
            with open(FileStorage._FileStorage__file_path, "r") as file:
                contents = file.read()
                self.assertGreater(len(contents), 0)
                self.assertTrue(f'"BaseModel.{base.id}"' in contents)
                self.assertTrue(f'"{base.updated_at.isoformat()}"' in contents)
                self.assertTrue(f'"{base.created_at.isoformat()}"' in contents)
                self.assertTrue('100100' in contents)
                self.assertTrue('"078 555 7832"' in contents)

    def test_save_update(self):
        """Test if update_at is changed during save"""
        base = BaseModel()
        initial_time = base.updated_at
        base.save()
        time_after_save = base.updated_at
        self.assertGreater(time_after_save, initial_time)


if __name__ == '__main__':
    unittest.main()
