#!/usr/bin/python3

"""
This module constains the FileStorage class for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""

import json


class FileStorage:
    """serializes instances to a JSON file and deserializes
    JSON file to instances
    """

    __file_path = ""
    __objects = {}

    def all(self):
        """returns the dictionary __objects"""
        return FileStorage.__objects

    def new(self, obj):
        """updates __objects dictionary with entry : {<obj class name>.id: obj}
        """
        FileStorage[f"{obj.__class__.__name__}.{obj.id}"] = obj

    def save(self):
        """serializes __objects to the JSON file (path: __file_path)"""
        with open(FileStorage.__file_path, "w") as file:
            json.dump(FileStorage.__objects, file)

    def reload(self):
        """deserializes the JSON file to __objects 
        (only if the JSON file (__file_path) exists ; otherwise, do nothing.
        If the file doesnt exist, no exception should be raised)
        """
        try:
            with open(FileStorage.__file_path, "r") as file:
                FileStorage.__objects = json.load(file)

        except FileNotFoundError:
            pass
