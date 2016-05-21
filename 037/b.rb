N, Q = gets.split.map(&:to_i)

state = Array.new(N, 0)

Q.times do
  l, r, t = gets.split.map(&:to_i)
  for i in (l-1)...r do
    state[i] = t
  end 
end

state.each do |ele|
  puts ele
end