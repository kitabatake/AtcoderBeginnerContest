N, K = gets.split.map(&:to_i)
arr = gets.split.map(&:to_i)

sum = 0

for i in 1..N do
  
  if i < K
    sum += arr[i-1] * i
  elsif (N - i + 1) < K
    sum += arr[i-1] * (N - i + 1)
  else
    sum += arr[i-1] * K
  end
end

puts sum