
//
//  d.cpp
//  Iris&Coolspring
//
//  Created by Kieran Will on 4/22/17.
//  Copyright © 2017 liuw53. All rights reserved.
//

#include "d.hpp"

class LOCATION_SERVICE{};
class newStaticServiceFetcher{};
int registerService(LOCATION_SERVICE, newStaticServiceFetcher);

int main() {
    registerService(LOCATION_SERVICE, newStaticServiceFetcher() {
        publicObjectcreateStaticService(){
            IBinderb=ServiceManager.getService(LOCATION_SERVICE);
            returnnewLocationManager(ILocationManager.Stub.asInterface(b));
    }};
}


