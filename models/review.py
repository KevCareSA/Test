#!/usr/bin/python3

"""
This module constains the Review class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class Review(BaseModel):
    """This class contains information on Review instances

    Attributes <PUBLIC>:
        place_id(str): contains <Place obj>.id
        user_id(str): contains <User obj>.id
        text = holds the written text of a User instances Review on Place
    """
    place_id = ""
    user_id = ""
    text = ""
