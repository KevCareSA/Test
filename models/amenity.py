#!/usr/bin/python3
""" State Module for HBNB project """
from models.base_model import BaseModel


class Amenity(BaseModel):
    """This class contains information on Amenity instances

    Attributes <PUBLIC>:
        name(str): name of Amenity provided
    """
    name = ""
