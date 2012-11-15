require_relative 'command'
require_relative 'communication'
require_relative 'key'
require_relative 'game_info'

class Client
    def run
        if ARGV.length != 4
            print_help
            exit
        end

        team_name = ARGV[0]
        password = ARGV[1]
        match_token = ARGV[2]
        host_name = ARGV[3]

        puts 'Starting Battle Tetris Client...'

        cmd = Command.new
        comm = Communication.new(host_name)
        comm.set_sub(match_token)

        connect_cmd = cmd.getMatchConnectCommand(team_name, match_token, password)

        puts 'Connecting to server...'
        client_token = comm.send(connect_cmd, Key::CLIENT_TOKEN)
        puts 'Received client token... ' + client_token

        game_info = GameInfo.new(
            Key::CLIENT_TOKEN=>client_token,
            Key::TEAM_NAME=>team_name)

        #
        # ADD ALGORITHM
        puts 'Missing algorithm...'
        #
        #

        puts 'Exiting...'

        comm.close
    end

    def print_help
        puts('usage: Client.rb <team-name> <password> <match-token> <host-name>');
    end
end

if __FILE__ == $0
    x = Client.new
    x.run
end