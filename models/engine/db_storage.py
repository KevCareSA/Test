#!/usr/bin/python3
"""This module defines a class to manage database storage for hbnb clone"""

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, scoped_session
from os import getenv
from models.amenity import Amenity
from models.place import Place
from models.review import Review
from models.state import State
from models.city import City
from models.user import User
from models.base_model import Base


class DBStorage:
    """This class manages storage of hbnb models using SQLAlchemy"""
    __engine = None
    __session = None

    def __init__(self):
        """The constructor for DBStorage"""
        user = getenv('HBNB_MYSQL_USER')
        passwd = getenv('HBNB_MYSQL_PWD')
        host = getenv('HBNB_MYSQL_HOST')
        database = getenv('HBNB_MYSQL_DB')
        env = getenv('HBNB_ENV')

        self.__engine = create_engine("mysql+mysqldb://{}:{}@{}/{}"
                                      .format(user, passwd, host, database),
                                      pool_pre_ping=True)

        if env == 'test':
            Base.metadata.drop_all(self.__engine)

    def all(self, cls=None):
        """query on the current database session (self.__session)
        all objects depending of the class name
        """
        objdict = {}
        if cls is None:
            classes = [User, State, City, Amenity, Place, Review]
            for cls_entry in classes:
                for obj in self.__session.query(cls_entry):
                    clsname = cls_entry.__name__
                    objdict[f"{clsname}.{obj.id}"] = obj
        else:
            for obj in self.__session.query(cls):
                clsname = cls.__name__
                objdict[f"{clsname}.{obj.id}"] = obj

        return objdict

    def new(self, obj):
        """add the object to the current database session (self.__session)"""
        self.__session.add(obj)

    def save(self, obj):
        """commit all changes of the current database session (self.__session)
        """
        self.__session.commit()

    def delete(self, obj=None):
        """delete from the current database session obj if not None"""
        if obj is not None:
            self.__session.delete(obj)

    def reload(self):
        """"""
        Base.metadata.create_all(self.__engine)

        sesn = sessionmaker(bind=self.__engine, expire_on_commit=False)
        Session = scoped_session(sesn)
        session = Session()

        self.__session = session
