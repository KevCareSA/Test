#!/usr/bin/python3

"""
This module constains the BaseModel class for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""

import models
from uuid import uuid4
from datetime import datetime


class BaseModel:
    """Base Class for all other classes in the HBnB console

    Attributes <PRIVATE>:
        id(str): contains object id using uuid4
        created_at(datetime): contains the time at which an object was created
        updated_at(datetime): contains the time at which an object was updated
    """
    def __init__(self, *args, **kwargs):
        """constructor for the base class"""
        self.id = str(uuid4())
        self.created_at = datetime.today()
        self.updated_at = datetime.today()

        iso_format = "%Y-%m-%dT%H:%M:%S.%f"

        if kwargs != {}:
            for k, val in kwargs.items():
                if k == '__class__':
                    continue
                if k == 'created_at' or k == 'updated_at':
                    self.__dict__[k] = datetime.strptime(val, iso_format)
                else:
                    self.__dict__[k] = val

        else:
            models.storage.new(self)

    def __str__(self):
        """unofficial string representation of an instance"""
        return f"[{self.__class__.__name__}] ({self.id}) {self.__dict__}"

    def save(self):
        """updates the datetime of the public instance: updated_at attribute"""
        self.updated_at = datetime.today()
        models.storage.save()

    def to_dict(self):
        """returns dictionary of all keys/values of __dict__ of an instance"""
        custom = self.__dict__.copy()
        custom["__class__"] = self.__class__.__name__
        custom["created_at"], custom["updated_at"] = \
            custom["created_at"].isoformat(), custom["updated_at"].isoformat()
        return custom
