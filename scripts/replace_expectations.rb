
# this line has been replaced with int _ instead of string:
#    expectThat("in fact, it's a pointer manipulation II",_______,string(s2+16));

puts __FILE__
dirname =  File.dirname(File.realpath(__FILE__))
require File.join(dirname,'./replacer')

sourcedirname = "src"
targetdir = "koans"

r = Replacer.new
r.doit File.join(File.dirname(File.realpath(__FILE__)),'..'),sourcedirname,targetdir


