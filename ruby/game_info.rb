require_relative 'key'

class GameInfo

    def initialize(info)
        @client_token = info[Key::CLIENT_TOKEN]
        @team_name = info[Key::TEAM_NAME]
    end

    def print
        puts 'client_token: ' + @client_token
        puts 'team_name: ' + @team_name
    end

    def hash
        hash = Hash.new
        hash[Key::CLIENT_TOKEN] = @client_token
        hash[Key::TEAM_NAME] = @team_name
        hash
    end
end