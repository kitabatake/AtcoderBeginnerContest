N, K = gets.split.map(&:to_i)
arr = gets.split.map(&:to_i)

sum = 0

ruiseki = []
arr.each do |ele|
  sum += ele
  ruiseki.push sum
end

sum = 0

for i in 0..(N-K) do
  if i == 0
    sum += ruiseki[i + K - 1]
  else
    sum += ruiseki[i + K - 1] - ruiseki[i - 1]
  end
end

puts sum