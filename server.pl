use 5.016;
use warnings;
use strict;
my $server_port = 8082;
my $server = IO::Socket::INET->new(LocalPort => $server_port,
Type => SOCK_STREAM, Reuse => 1, Listen =>10) or die "err $@";
say "Start server";
while (my $client = $server->accept()) {
    say "New client";
    $client->autoflush(1);
    my $message = <$client>; chomp($message);
    print $client "The Echo: ".$message;
    close($client);
    last if $message eq 'END';
}
close($server);
