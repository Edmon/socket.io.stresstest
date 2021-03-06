Stresstest client for socket.io
===============================

Usage:

    ./manyclients.sh [-v] [-w seconds] 100 http(s)://host/ inputfile

``-v`` will show you the received responses.

``-w`` (seconds) will spawn a new process only every (seconds) seconds, instead of all at once

``100`` will spawn one hundred socket.io clients at once.

``http(s)://host/`` should be set to your socket.io server address.

``inputfile`` should be a json list with the exact requests the browser would send to your backend:

    [
        "5:::{\"name\":\"login\",\"args\":[{\"user\":\"michaeljackson\",\"password\":\"beatit\"}]}",
        "5:::{\"name\":\"poke\",\"args\":[{\"target\":\"prince\",\"sessionid\":\"%1%\"}]}",
        "0::"
    ]

the stresstest will execute all these requests in that order and ignore the
responses, except in one special case.

Notice the ``%1%`` in the second request? That will be replaced with the sessionid
returned in the first request. Modify ``_parse_session_id`` inside
SocketIOHandler.cpp to parse it correctly from you login response.

You can probably make the client click through most of your site this way.
Always send ``0::`` as the last message.

Requirements
------------

You need to have BOOST installed on your system. I included the other
dependencies in the ``parts`` directory because I developed this in svn.

This software was tested on mac osx and ubuntu.
