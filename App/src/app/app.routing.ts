import { BtPageComponent } from './bt-page/bt-page.component';
import { MainPageComponent } from './main-page/main-page.component';
import { DataPageComponent } from './data-page/data-page.component';
import { InputPageComponent } from './input-page/input-page.component';
import { AboutPageComponent } from './about-page/about-page.component';

export const appRoutes: any = [
    { path: "", component: MainPageComponent },
    { path: "mainPage/:route", component: MainPageComponent },
    { path: "btPage/:route", component: BtPageComponent },
    { path: "dataPage/:route", component: DataPageComponent },
    { path: "inputPage/:route", component: InputPageComponent },
    { path: "aboutPage/:route", component: AboutPageComponent }
];

export const appComponents: any = [
    MainPageComponent,
    BtPageComponent
];
