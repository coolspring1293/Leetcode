//
//  AppDelegate.swift
//  Iris&Coolspring
//
//  Created by Kieran Will on 11/21/16.
//  Copyright © 2016 liuw53. All rights reserved.
//

import Cocoa
import ServiceManagement

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {


    @IBOutlet weak var statusMenu: NSMenu!
    @IBOutlet weak var loginOnStartupItem: NSMenuItem!
    var statusItem: NSStatusItem?
    var hoop = false;

    
    func applicationDidFinishLaunching(aNotification: NSNotification) {
        // Insert code here to initialize your application
        statusItem = NSStatusBar.systemStatusBar().statusItemWithLength(NSVariableStatusItemLength)
        statusItem?.menu = statusMenu
        statusItem?.highlightMode = true

        
        fetch()
        NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: #selector(AppDelegate.fetch), userInfo: nil, repeats: true)
    }

    
    
    func applicationWillTerminate(aNotification: NSNotification) {
        // Insert code here to tear down your application
    }

    
    func fetch() {
        let date = NSDate()
        
        let timeFormatter = NSDateFormatter()
        timeFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        let dateAsString = "2016-09-15 23:00:00"
        let date1 = timeFormatter.dateFromString(dateAsString)!
        
        let timeFormatter2 = NSDateFormatter()
        timeFormatter2.dateFormat = "HH:mm:ss"
        let strNowTime = timeFormatter2.stringFromDate(date) as String
        self.statusItem?.title = strNowTime
        
        
        let diffDateComponents = NSCalendar.currentCalendar().components([
//            NSCalendarUnit.Year,
//            NSCalendarUnit.Month,
            NSCalendarUnit.Day,
            NSCalendarUnit.Hour,
            NSCalendarUnit.Minute,
            NSCalendarUnit.Second],
            fromDate: date1,
            toDate: date,
            options: NSCalendarOptions.init(rawValue: 0))
        
        
        
        hoop = !hoop;
        var tmpS = "💗";//💗
        if (hoop) {
            tmpS = "💖";
        }
        
        let strNowTime2 = tmpS + "Love you for \(diffDateComponents.day) d, \(diffDateComponents.hour) h, \(diffDateComponents.minute) min, \(diffDateComponents.second) s";
        
        self.statusItem?.title = strNowTime2
    }
    

    
    @IBAction func quit(menuItem: NSMenuItem) {
        NSApplication.sharedApplication().terminate(self)
    }
    

}

