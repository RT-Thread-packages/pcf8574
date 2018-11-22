from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

# add pcf8574 src files.
if GetDepend('PKG_USING_PCF8574'):
    src += Glob('pcf8574.c')

if GetDepend('PKG_USING_PCF8574_SAMPLE'):
    src += Glob('pcf8574_sample.c')

# add pcf8574 include path.
path  = [cwd]

# add src and include to group.
group = DefineGroup('pcf8574', src, depend = ['PKG_USING_PCF8574'], CPPPATH = path)

Return('group')
