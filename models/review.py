#!/usr/bin/python3
""" Review module for the HBNB project """
from models.base_model import BaseModel
from models.base_model import Base
import models
from sqlalchemy import Column, String, ForeignKey


class Review(BaseModel, Base):
    """ Review classto store review information """
    if models.storage_type == 'db':
        __tablename__ = 'reviews'
        text = Column(String(length=1024), nullable=False)
        place_id = Column(String(length=60), ForeignKey('places.id'),
                          nullable=False)
        user_id = Column(String(length=60), ForeignKey('users.id'),
                         nullable=False)
    else:
        place_id = ""
        user_id = ""
        text = ""
