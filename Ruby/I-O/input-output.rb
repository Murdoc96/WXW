#!/usr/bin/ruby
=begin
	input and output in ruby
=end

#irb >> interactive ruby shell
#irb --simple-prompt
#suma de parametros por default

def sumaNumbers(a = 37, b=53)
	return a+b
end

# los string tienen el metodo chmod that no considera el "\n"
def name(namei)
  return "hola " + namei + " Welcome"#namei->name input
end

# gets -> string
# gets.to_i -> entero
#ttttttttt

puts "numero1:"; var1 = gets.to_i
puts "numero 2"; var2 = gets.to_i
puts "suma por parametros: "; puts sumaNumbers(var1,var2)
puts "suma por argumnetos por defecto: "; puts sumaNumbers()

t = 36.12345
puts format("%.2f",t)



=begin
var = gets.chomp(); puts name(var)
=end
