# This is a surprising simple method to convert a dict into an object.
# For every object in Python, there is a special attribute named __dict__,
# where the object's (writable) attributes are stored. By simply update
# the __dict__ attribute would convert all keys in a dict into object's
# attributes!
# This method is first found in:
# http://stackoverflow.com/questions/1305532/convert-python-dict-to-object

class Struct:
    def __init__(self, **entries):
	self.__dict__.update(entries)

if __name__ == "__main__":
    d = {'a' : 1, 'b' : 2}
    s = Struct(**d)
    print s.a, s.b
