#!/usr/bin/python3

"""
This module constains the Amenity class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class Amenity(BaseModel):
    """This class contains information on Amenity instances

    Attributes <PUBLIC>:
        name(str): name of Amenity provided
    """
    name = ""
