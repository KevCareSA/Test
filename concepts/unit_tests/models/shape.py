class Shape:
    """This is a shape class"""
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def __str__(self):
        return (f"width: {self.width} | height: {self.height}")

    @property
    def width(self):
        return self.__width

    @width.setter
    def width(self, size):
        if type(size) != int:
            raise TypeError("width must be int")
        self.__width = size

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, size):
        if type(size) != int:
            raise TypeError("height must be int")
        self.__height = size
