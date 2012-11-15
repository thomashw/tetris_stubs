require 'json'
require_relative 'key'

class Command
    def getMatchConnectCommand(team_name, match_token, password)
        conn = Hash.new
        conn[Key::COMM_TYPE] = Key::MATCH_CONNECT
        conn[Key::TEAM_NAME] = team_name
        conn[Key::MATCH_TOKEN] = match_token
        conn[Key::PASSWORD] = password
        JSON.generate(conn)
    end
end