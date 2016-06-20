import energenie

energenie.init()

def incoming(address, message):
    # Only eTRV messages
    if address[1] == 3:
        print(message)

energenie.fsk_router.when_incoming(incoming)

while True:
    energenie.loop()
