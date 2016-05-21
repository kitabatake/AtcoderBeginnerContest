A, B, C = gets.split.map(&:to_i)

if A < B
  low = A
else
  low = B
end

puts C / low