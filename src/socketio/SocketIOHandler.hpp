#ifndef SOCKET_IO_HANDLER
#define SOCKET_IO_HANDLER

#include <websocketpp/roles/client.hpp>
#include <websocketpp/websocketpp.hpp>
#include "../sequence/ActionSequence.hpp"

using websocketpp::client;

namespace socketio {
    
    class SocketIOHandler : public client::handler {
    private:
        std::string sessionid;
        std::string _host;
        std::string _websocket_token;
        sequence::ActionSequence _actions;

        std::string _get_token(const std::string &host);
        std::string _parse_session_id(const std::string &message);
        void _log_message(const std::string &message, const boost::format &next_message);
    public:
        SocketIOHandler(const std::string &host, sequence::ActionSequence &action_sequence);
        std::string websocket_uri() const;
        void on_message(connection_ptr con, message_ptr msg);        
        virtual void on_load(connection_ptr connection, client::handler_ptr old_handler);
        virtual void on_close(connection_ptr connection);
        virtual void on_open(connection_ptr con);
        virtual void on_fail(connection_ptr con);
    };

}

#endif