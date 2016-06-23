from __future__ import print_function
import thread
import Queue
import json
import energenie
import energenie.OnAir
import energenie.OpenThings
import sys

readin = raw_input
q = Queue.Queue()
air_interface = energenie.OnAir.OpenThingsAirInterface()

energenie.init()

def incoming(address, message):
    # Only eTRV messages
    if address[1] == 3:
        # debugging: dump encoded message to stderr
        print("RX:", energenie.OpenThings.encode(message), file=sys.stderr)

        # write JSON representation of an OpenThings message to stdout
        sys.stdout.write(json.dumps(message.pydict))
        sys.stdout.write("\n")
        sys.stdout.flush()

def poller():
    while True:
        try:
            # parse JSON representation of an OpenThings message
            message = energenie.OpenThings.Message(pydict=json.loads(readin()))

            # add it to the queue
            q.put(message)
        except:
            # TODO: log errors to stderr
            pass

in_thread = thread.start_new_thread(poller, ())
energenie.fsk_router.when_incoming(incoming)

while True:
    energenie.loop()

    if not q.empty():
        # take top message from the queue and transmit it
        message = q.get()
        air_interface.send(message)

        # debugging: dump encoded message to stderr
        print("TX:", energenie.OpenThings.encode(message), file=sys.stderr)


# Test msg for stdin:
#{"header": {"sensorid": 2003, "productid": 3, "mfrid": 4}, "recs": [{"wr": true, "paramid": 116, "typeid": 144, "length": 2, "value": 15.0}]}
