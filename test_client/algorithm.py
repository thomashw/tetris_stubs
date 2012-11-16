import array
import random
import command
import communication
import json
import time

class Algorithm(object):
  SLEEP_TIME = 0.5

  def __init__(self, client_token, cmd, comm):
    self.cmd = cmd
    self.comm = comm
    self.client_token = client_token

  def run(self):
    game_moves = ['left', 'right', 'lrotate', 'rrotate', 'down']

    while True:
      recv = self.comm.receive(communication.Communication.Origin.PublishSocket)
      
      try:
        if(json.loads(recv)[command.Command.COMM_TYPE] == command.Command.MATCH_END):
          break
      except:
        continue

      index = random.randint(0,len(game_moves)-1)
      move = game_moves[index]
      move_command = self.cmd.getGameMoveCommand(move, self.client_token)
      self.comm.send(move_command)
      time.sleep(Algorithm.SLEEP_TIME)
