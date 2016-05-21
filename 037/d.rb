H, W = gets.split.map(&:to_i)

$arr = Array.new(H+2){ Array.new(W+2, -1) }
$cache = Array.new(H){ Array.new(W, nil) }

(1..H).each do |h| 
  $arr[h] = [-1] + gets.split.map(&:to_i).push(-1)
end


def solv (h, w)

  if $cache[h-1][w-1]
    return $cache[h-1][w-1] 
  end

  sum = 0
  current = $arr[h][w]
  
  dxs = [0, 1, 0, -1]
  dys = [-1, 0, 1, 0]

  for i in 0..3 do
    cx = w + dxs[i]
    cy = h + dys[i]
    sum += 1 + solv(cy, cx) if $arr[cy][cx] > current
  end

  $cache[h-1][w-1] = sum
end

sum = H * W

(1..H).each do |h| 
  (1..W).each do |w|
    sum += solv h, w
  end
end

puts sum % (10**9 + 7)