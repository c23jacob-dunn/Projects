from PIL import ImageGrab
import numpy as np
import cv2

while True:
    screen = np.array(ImageGrab.grab(bbox=(0,0,1920,1080)))
    cv2.imshow('Python Window', screen)

    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break