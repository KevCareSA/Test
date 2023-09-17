#!/usr/bin/python3
"""This module defines a class User"""
from models.base_model import BaseModel
from models.base_model import Base
import models
from sqlalchemy import Column, String


class User(BaseModel, Base):
    """This class defines a user by various attributes"""
    if models.storage_type == 'db':
        __tablename__ = 'users'
        email = Column(String(length=128), nullable=False)
        password = Column(String(length=128), nullable=False)
        first_name = Column(String(length=128), nullable=False)
        last_name = Column(String(length=128), nullable=False)
    else:
        email = ''
        password = ''
        first_name = ''
        last_name = ''
