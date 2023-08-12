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


class Test_instantiation(unittest.TestCase):
    """Tests instances of FileStorage"""
    def test_instances(self):
        """Test for instances"""
        fs = FileStorage()
        self.assertEqual(type(fs), FileStorage)
        self.assertFalse(isinstance(fs, BaseModel))

        with self.assertRaises(TypeError):
            FileStorage(self, 23442)

    def test_private_attributes_exist(self):
        """Test if private attributes exist"""
        self.assertTrue(hasattr(storage, "_FileStorage__file_path"))
        self.assertTrue(hasattr(storage, "_FileStorage__objects"))

    def test_class_attr_types(self):
        """Test private class attribute types"""
        fs = FileStorage()
        self.assertEqual(type(fs.all()), dict)
        self.assertEqual(type(FileStorage._FileStorage__file_path), str)


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

    def test_new_indirectly(self):
        """Tests the new functions dictionary assignment"""
        objdict = storage.all()
        for i in range(10):
            self.assertTrue(f"BaseModel.{self.base[i].id}" in objdict.keys())
            self.assertTrue(f"User.{self.usr[i].id}" in objdict.keys())
            self.assertEqual(objdict[f"BaseModel.{self.base[i].id}"],
                             self.base[i])
            self.assertEqual(objdict[f"User.{self.usr[i].id}"], self.usr[i])

    def test_new_multiple_args(self):
        """Tests new function with muliple args"""
        fs = FileStorage()
        with self.assertRaises(TypeError):
            fs.new()


class Test_Save_Reload(unittest.TestCase):
    """Test the serialization and deserializatin of json files
    using save and reload
    """
    def setUp(self):
        """initializes objects to save"""
        self.base = BaseModel()

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

        with self.assertRaises(TypeError):
            storage.save(1234, 239)

    def test_save_object_change(self):
        filepath = FileStorage._FileStorage__file_path
        b = BaseModel()
        b.food = "Lasagna"
        b.age = 22
        b.altitude = 9000.52
        b.save()
        if os.path.exists(filepath):
            with open(filepath, "r") as file:
                content = file.read()
                self.assertTrue('"Lasagna"' in content)
                self.assertTrue('"food"' in content)
                self.assertTrue('"age"' in content)
                self.assertTrue('22' in content)
                self.assertFalse('"22"' in content)
                self.assertTrue('"altitude"' in content)
                self.assertTrue('9000.52' in content)
                self.assertFalse('"9000.52"' in content)

    def test_reload_normal(self):
        """Test normal functioning of reload"""
        fs = FileStorage()
        FileStorage._FileStorage__objects = {}
        base = BaseModel()
        base.save()
        fs.reload()
        fstring = f"BaseModel.{base.id}"
        self.assertIn(fstring, fs.all().keys())
        self.assertIn("id", fs.all()[fstring].to_dict())
        self.assertIn("updated_at", fs.all()[fstring].to_dict())
        self.assertIn("created_at", fs.all()[fstring].to_dict())

    def test_reload_without_file(self):
        """Test normal functioning of reload"""
        fs = FileStorage()
        FileStorage._FileStorage__objects = {}
        if os.path.exists(FileStorage._FileStorage__file_path):
            os.remove(FileStorage._FileStorage__file__path)
        fs.reload()

    def test_reload_with_extra_args(self):
        """Test normal functioning of reload"""
        fs = FileStorage()
        with self.assertRaises(TypeError):
            fs.reload(1234)


if __name__ == '__main__':
    unittest.main()
