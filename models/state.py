#!/usr/bin/python3

"""
This module constains the State class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class State(BaseModel):
    """This class contains information on State instances

    Attributes <PUBLIC>:
        name(str): name of the State
    """
    name = ""
