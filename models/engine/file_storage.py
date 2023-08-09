#!/usr/bin/python3

"""
This module constains the FileStorage class for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""


import json
from models.base_model import BaseModel
from models.user import User
from models.state import State
from models.city import City
from models.place import Place
from models.amenity import Amenity
from models.review import Review


class FileStorage:
    """Handles with serialization/deserialization of objects to/from JSON

    Attributes <PUBLIC>:
        __file_path(str): contains path to json file
        __objects: contain a dictionary of instances of all Classes
    """

    __file_path = "file.json"
    __objects = {}

    def all(self):
        """returns the dictionary __objects"""
        return FileStorage.__objects

    def new(self, obj):
        """updates __objects dictionary with entry : {<obj class name>.id: obj}
        """
        FileStorage.__objects[f"{obj.__class__.__name__}.{obj.id}"] = obj

    def save(self):
        """serializes __objects to the JSON file (path: __file_path)"""
        clsdict = FileStorage.__objects
        dict_obj = {o: clsdict[o].to_dict() for o in clsdict.keys()}
        with open(FileStorage.__file_path, "w") as file:
            json.dump(dict_obj, file)

    def reload(self):
        """deserializes the JSON file to __objects
        (only if the JSON file (__file_path) exists ; otherwise, do nothing.
        If the file doesnt exist, no exception should be raised)
        """
        try:
            with open(FileStorage.__file_path, "r") as file:
                dict_obj = json.load(file)
                for obj in dict_obj.values():
                    clsname = obj["__class__"]
                    del obj["__class__"]
                    self.new(eval(clsname)(**obj))

        except FileNotFoundError:
            pass
