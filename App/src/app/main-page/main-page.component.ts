import { Component, OnInit } from '@angular/core';
import { RadSideDrawer } from "nativescript-ui-sidedrawer";
import { BtService } from "../bt.service";
import { UserIn } from "../inputData";
import { Facts } from "../facts";

@Component({
    selector: 'ns-main-page',
    templateUrl: './main-page.component.html',
    styleUrls: ['./main-page.component.css'],
    moduleId: module.id,
})

export class MainPageComponent implements OnInit {
    constructor(private bt: BtService) { }

    botString = "Bottles left: " + UserIn.bottleCount;

    ngOnInit(): void {

    }

    openDrawer() { //opens side drawer
        const sideDrawer = new RadSideDrawer;
        sideDrawer.showDrawer();
    }

    sendFire() {
        if (UserIn.bottleCount > 0) { //so ir won't go under 0
            this.bt.sendBTData("<1000000>"); //sends fire command
            UserIn.bottleCount --;
            Facts.quant ++;
            Facts.distance += 100;
            this.botString = "Bottles left: " + UserIn.bottleCount;
        }
    }

    sendReload(){
        this.bt.sendBTData("<2000000>"); //sends reload command
    }
}
