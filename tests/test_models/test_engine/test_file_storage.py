#!/usr/bin/python3

"""
This module constains the FileStorage class for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""

import models.engine.file_storage as fs_module
from models.engine.file_storage import FileStorage
import unittest
import os
from models.base_model import BaseModel
from models.user import User
from models import storage


class Test_FS_doc(unittest.TestCase):
    """Test FileStorage Documentation"""
    def test_module_doc(self):
        """Test module documentation"""
        self.assertGreaterEqual(len(fs_module.__doc__), 1)

    def test_class_doc(self):
        """Test class documentation"""
        self.assertGreaterEqual(len(FileStorage.__doc__), 1)

    def test_function_doc(self):
        """Test function documentation"""
        self.assertGreaterEqual(len(FileStorage.all.__doc__), 1)
        self.assertGreaterEqual(len(FileStorage.new.__doc__), 1)
        self.assertGreaterEqual(len(FileStorage.save.__doc__), 1)
        self.assertGreaterEqual(len(FileStorage.reload.__doc__), 1)


class Test_Functions(unittest.TestCase):
    """Tests the functions of FileStorage"""

    def setUp(self):
        """Initialized some objects to be stored in dictionary"""
        self.usr = [User() for _ in range(10)]
        self.base = [BaseModel() for _ in range(10)]

    def test_all(self):
        """Tests the all functions return"""
        objdict = storage.all()
        self.assertEqual(FileStorage._FileStorage__objects, objdict)

    def test_new(self):
        """Tests the new functions dictionary assignment"""
        objdict = storage.all()
        for i in range(10):
            self.assertTrue(f"BaseModel.{self.base[i].id}" in objdict.keys())
            self.assertTrue(f"User.{self.usr[i].id}" in objdict.keys())
            self.assertEqual(objdict[f"BaseModel.{self.base[i].id}"],
                             self.base[i])
            self.assertEqual(objdict[f"User.{self.usr[i].id}"], self.usr[i])


class Test_Save_Reload(unittest.TestCase):
    """Test the serialization and deserializatin of json files
    using save and reload
    """
    def setUp(self):
        """initializes objects to save"""
        self.base = BaseModel

    def tearDown(self):
        """the tear down method that activates when a function is finished
        executing
        """
        filepath = FileStorage._FileStorage__file_path
        if os.path.exists(filepath):
            os.remove(filepath)

    def test_save_file_exists(self):
        """check if saving creates file"""
        storage.save()
        self.assertTrue(os.path.exists(FileStorage._FileStorage__file_path))


if __name__ == '__main__':
    unittest.main()
