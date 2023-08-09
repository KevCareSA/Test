#!/usr/bin/python3

"""
This module constains the City class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class City(BaseModel):
    """This class contains information on City Instances

    Attributes <PUBLIC>:
        state_id(str): id of a State instance
        name(str): name of City instance
    """
    state_id = ""
    name = ""
