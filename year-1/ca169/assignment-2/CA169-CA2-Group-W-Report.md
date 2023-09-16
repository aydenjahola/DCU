# CA169 CA2 Group W Report

## Part 2 – Wireshark
1. To clear the ARP cache, I opened the command prompt and entered the command `arp -d`. This command deletes the ARP cache entries.

![](https://media.discordapp.net/attachments/1030082704345145435/1095820544034738436/image.png)

2. I opened Google Chrome as my web browser.
3. To flush the DNS cache, I entered the command `ipconfig /flushdns` in the command prompt.

![](https://media.discordapp.net/attachments/1030082704345145435/1095820498614632610/image.png)

4. I cleared the cache on Google Chrome by clicking on the three dots at the top right corner, selecting "Settings," selecting "Privacy and Security," and clicking on "Clear browsing data." Finally, I clicked on "Clear data."

![](https://media.discordapp.net/attachments/1030082704345145435/1095823091973763162/image.png)

5. I started Wireshark and began capturing traffic.
6. I chose the website "www.linux.org" and connected to it while Wireshark was capturing.
7. Once the website was displayed, I stopped the Wireshark capture.
8. To find the start of the interaction with the website, I used a filter. I wrote a filter using the expression `http.host == linux.org" to capture only the traffic that is related to the website "linux.org`. This allowed me to easily find the IP address of the website communicating with my machine.

![](https://i.imgur.com/KMLlXjk.png)

![](https://i.imgur.com/4oH63Es.png)

9. The screenshot of the Wireshark window clearly shows the start of the interaction with the selected website. The first packet is a DNS query from my computer to the DNS server asking for the IP address of `linux.org`. The second packet is a DNS response from the DNS server with the IP address of `linux.org`. The third packet is a TCP SYN packet from my computer to the IP address of `linux.org`, indicating the start of the three-way handshake.
10. The three packets that established the TCP three-way-handshake for the website interaction are:
    - Packet 1: DNS Query
    - Packet 2: DNS Response
    - Packet 3: TCP SYN

The three packets involve the following steps:
 - Packet 1: My computer sends a DNS query to the DNS server asking for the IP address of `linux.org`.
 - Packet 2: The DNS server responds with the IP address of `linux.org`.
 - Packet 3: My computer sends a TCP SYN packet to the IP address of `linux.org`, indicating the start of the three-way handshake.

![](https://media.discordapp.net/attachments/1030082704345145435/1095811196298473615/image.png)

11. To select only these three frames, I used the filter expression `tcp.flags.syn == 1 && tcp.flags.ack == 0`. This filter selects all packets with the SYN flag set and the ACK flag not set, which includes the three packets involved in the TCP three-way handshake.

![](https://i.imgur.com/Uk3maWQ.png)

12. The content of the file are included the submission document as FollowTCPStream and screenshot can also be found below:

![](https://media.discordapp.net/attachments/1030082704345145435/1095831321500201031/image.png)

13. Here are the contents of the CAP file:
    - The GET request made includes the following headers:
    ```
    HTTP method: GET
    Request URI: "/"
    HTTP version: HTTP/1.1
    Host: linux.org
    Connection: keep-alive
    Upgrade-Insecure-Requests: 1
    User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/112.0.0.0 Safari/537.36
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,/;q=0.8,application/signed-exchange;v=b3;q=0.7
    Accept-Encoding: gzip, deflate
    Accept-Language: en-US,en;q=0.9
    ```
    - The response from the server includes the following headers:
    ```
    HTTP version: HTTP/1.1
    HTTP response code: 301 Moved Permanently
    Date: Wed, 12 Apr 2023 20:07:08 GMT
    Content-Type: text/html
    Transfer-Encoding: chunked
    Connection: keep-alive
    Location: https://linux.org/
    CF-Cache-Status: DYNAMIC
    Report-To: {"endpoints":[{"url":"https://a.nel.cloudflare.com/report/v3?s=0wH5mbRagaSHfRUtmgUUZk7IY1HxTY7dTYcfbh1f2dZgp6JwWQZfOcIXPvrfrMLuODErpgSk90C%2F52uAVsTeGUEy4ZrfXti%2BVjJAH8DKIWtVDQ8oJR59RSp%2B3Q%3D%3D"}],"group":"cf-nel","max_age":604800}
    NEL: {"success_fraction":0,"report_to":"cf-nel","max_age":604800}
    Server: cloudflare
    CF-RAY: 7b6e1807ca3e0892-LHR
    ```
    - The body of the response is also included and is a chunk of HTML code that indicates that the requested resource has been permanently moved to a new URL.
    - The HTTP response codes used in the interaction are:
        - **301 Moved Permanently**: This status code indicates that the requested resource has been permanently moved to a new URL, which is provided in the "Location" header. The client should update its bookmarks and links to use the new URL.
        - **200 OK**: This status code indicates that the server has successfully processed the client's request and is returning the requested resource in the message body. However, in this interaction, the 200 OK status code was not used.
