use IO::Socket; 
use 5.016;
use warnings;
use strict;
my $remote_host = '78.47.129.69';
my $remote_port = 8082;
my $socket = IO::Socket::INET->new(PeerAddr => 
$remote_host, PeerPort => $remote_port, Proto => 
"tcp", Type => 
SOCK_STREAM) or die "Couldn't connect to $remote_host:$remote_port : $@\n"; 

print $socket "Why don't you call me anymore?\n"; 
my $answer = <$socket>; 
say $answer;
close($socket);

