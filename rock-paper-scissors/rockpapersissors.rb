# ROCK PAPER SCISSORS TESTING 

playagain = "Y"

loop do
  moves = ["ROCK","PAPER","SCISSORS"]
  puts "Rock, paper, scissors, shoot!"
  player = gets.chomp.upcase
  computer = rand(0..2)
  puts "YOU: #{player} \n"
  puts "COMPUTER: #{moves[computer]} \n"

  if player == computer then
    puts "Tie! \n"
  end
    
  if player == "ROCK"
    if moves[computer] == "PAPER" then
      puts "You Lose! \n"
    elsif moves[computer] == "SCISSORS" then 
      puts "You Win! \n"
    end
    
  elsif player == "PAPER"
    if moves[computer] == "SCISSORS" then
      puts "You Lose! \n"
    elsif moves[computer] == "ROCK" then
      puts "You Win! \n"
    end
    
  elsif player == "SCISSORS"
    if moves[computer] == "ROCK" then
      puts "You Lose! \n"
    elsif moves[computer] == "PAPER" then
      puts "You Win! \n"
    end

  else
    puts "Computer wins due to PLAYER's typo."
  end

  puts "Play again? (Y/N)"
  playagain = gets.chomp.upcase
  while playagain != "Y" && playagain != "N" do
    puts "Play again? (Y/N)"
    playagain = gets.chomp.upcase
  end
  
  if playagain == "N" then
    puts "Thanks for playing!"
    break 
  end
end