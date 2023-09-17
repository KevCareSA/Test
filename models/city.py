#!/usr/bin/python3
""" City Module for HBNB project """
from models.base_model import BaseModel
from models.base_model import Base
import models
from sqlalchemy import Column, String, ForeignKey


class City(BaseModel, Base):
    """ The city class, contains state ID and name """
    if models.storage_type == 'db':
        __tablename__ = 'cities'
        state_id = Column(String(length=60), ForeignKey('states.id'),
                          nullable=False)
        name = Column(String(length=128), nullable=False)
    else:
        state_id = ''
        name = ''
