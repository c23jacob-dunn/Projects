from PIL import ImageGrab
import time

im=ImageGrab.grab()

moment=time.strftime("%Y-%b-%d__%H_%M_%S",time.localtime())
im.save(moment+"Screenshot.jpg")