
# this line has been replaced with int _ instead of string:
#    expectThat("in fact, it's a pointer manipulation II",_______,string(s2+16));

puts __FILE__
dirname =  File.dirname(File.realpath(__FILE__))
require File.join(dirname,'./replacer')

sourcedirname = "src"
targetdir = "koans"

puts "WARNING - this will modify the actual source files!"
puts "if you want to continue type 'yes'"
confirmation = gets 
confirmation.strip!
confirmation = "yes"
if ("yes" == confirmation)
  puts "OK...."
  r = Replacer.new
  r.doit File.join(File.dirname(File.realpath(__FILE__)),'..'),sourcedirname,targetdir
 else 
  puts "not doing anything"
end


