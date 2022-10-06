def convertRGP(red, blue, green):
    red = 1 - (red / 255) 
    blue = 1 - (blue / 255) 
    green = 1 - (green / 255) 
    return red, blue, green


print(convertRGP(139,69,19))