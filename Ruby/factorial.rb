=begin
this algortim return the factorial of any number
=end
#require_relative 'saludo'
def Factorial(n)
	if(n == 0)
		return 1
	else
		return n * Factorial(n-1)
	end

end

puts Factorial(ARGV[0].to_i), "\n"
