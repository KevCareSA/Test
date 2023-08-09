#!/usr/bin/python3

"""
This module constains the User class which inherits Basemodel

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 09/08/2023
"""


from models.base_model import BaseModel


class User(BaseModel):
    """Inherits BaseModel classs

    Attributes <PUBLIC>:
        email(str): A Users email address
        password(str): A Users email password
        first_name(str): String representation of users first name
        last_name(str): String representation of users last name
    """
    email = ""
    password = ""
    first_name = ""
    last_name = ""
