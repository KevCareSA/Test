#!/usr/bin/python3

"""
This module constains the BaseModel class for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""
# "%Y-%m-%dT%H:%M:%S.%f"

from uuid import uuid4
from datetime import datetime


class BaseModel:
    """Base class for the HBnB console"""
    def __init__(self, *args, **kwargs):
        """constructor for the base class"""
        self.id = str(uuid4())
        self.created_at = datetime.today()
        self.updated_at = datetime.today()

        iso_format = "%Y-%m-%dT%H:%M:%S.%f"

        if kwargs != {}:
            for k, v in kwargs.items():
                if k == '__class__':
                    continue
                if k == 'created_at' or k == 'updated_at':
                    self.__dict__[k] = datetime.strptime(v, iso_format)
                else:
                    self.__dict__[k] = v

    def __str__(self):
        """unofficial string representation of an instance"""
        return f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}"

    def save(self):
        """updates the datetime of the public instance: updated_at attribute"""
        self.updated_at = datetime.today()

    def to_dict(self):
        """returns dictionary of all keys/values of __dict__ of an instance"""
        custom = self.__dict__.copy()
        custom["__class__"] = self.__class__.__name__
        custom["created_at"], custom["updated_at"] = \
            custom["created_at"].isoformat(), custom["updated_at"].isoformat()
        return custom


if __name__ == '__main__':
    my_model = BaseModel()
    my_model.name = "My_First_Model"
    my_model.my_number = 89
    print(my_model.id)
    print(my_model)
    print(type(my_model.created_at))
    print("--")
    my_model_json = my_model.to_dict()
    print(my_model_json)
    print("JSON of my_model:")
    for key in my_model_json.keys():
        print("\t{}: ({}) - {}".format(key, type(my_model_json[key]),
                                       my_model_json[key]))

    print("--")
    my_new_model = BaseModel(**my_model_json)
    print(my_new_model.id)
    print(my_new_model)
    print(type(my_new_model.created_at))

    print("--")
    print(my_model is my_new_model)
