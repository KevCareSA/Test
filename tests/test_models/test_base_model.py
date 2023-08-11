#!/usr/bin/python3

"""
Test module for base_model.py and the BaseModel class
"""

import unittest
from time import sleep
from datetime import datetime
import models.base_model as bm_module
from models.base_model import BaseModel


class Test_BM_Doc(unittest.TestCase):
    """Tests for BaseModel class Documentation"""
    def test_module_doc(self):
        """tests BaseModel module documentation"""
        self.assertGreater(len(bm_module.__doc__), 1)

    def test_class_doc(self):
        """Test BaseModel class documentation"""
        self.assertGreater(len(BaseModel.__doc__), 1)

    def test_builtin_doc(self):
        """Test builtin documentation"""
        self.assertGreater(len(BaseModel.__init__.__doc__), 1)
        self.assertGreater(len(BaseModel.__str__.__doc__), 1)

    def test_custom_doc(self):
        """Test custom documentation"""
        self.assertGreater(len(BaseModel.save.__doc__), 1)
        self.assertGreater(len(BaseModel.to_dict.__doc__), 1)


class Test_BM_Instantiation(unittest.TestCase):
    """Test BaseModel instantiation"""

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
        base2 = BaseModel()
        self.assertEqual(base.id[14], '4')
        self.assertEqual(base2.id[14], '4')

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
        base = BaseModel
        self.assertEqual(type(base), dict)


if __name__ == '__main__':
    unittest.main()
