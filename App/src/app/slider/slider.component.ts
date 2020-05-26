import { ActivatedRoute } from '@angular/router';
import { Component, OnInit } from "@angular/core";
import { BtService } from "../bt.service";
import { sliders } from "../sliders";
import { Input } from "@angular/core";

@Component({
    selector: "ns-slider",
    templateUrl: "./slider.component.html",
    styleUrls: ["./slider.component.css"],
    moduleId: module.id,
})
export class SliderComponent implements OnInit {
    @Input() compId: number;

    sliderValue;
    sliderName;
    sliderMaxValue;
    sliderId;

    slider = sliders;

    constructor(private route: ActivatedRoute, private bt: BtService) {
    }

    ngOnInit(): void {
    }

    sliderInput(args){ //reads slider value from input
        this.slider[this.compId].value = args.value;
        this.bt.sendBTData("<0" + this.btBuild(this.slider[0].value) + this.btBuild(this.slider[1].value) + ">");
    }

    btBuild(value){ //builds bt send out data
        if(value>=100)
            return value.toString();
        else if (value >= 10 && value < 100)
            return "0" + value.toString();
        else
            return "00" + value.toString();
    }
}
