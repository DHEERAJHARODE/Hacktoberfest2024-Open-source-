
import { Logos, Content, Sidebar } from "../../components";
import './style.css';

export default function AuthLayout({children, sideTitle, sideText, sideBtnText, sideBtnURL, heading, subText}) {
   
    return (
        <>
            <Content>
                <div className="row g-0">
                    <div className="sidemenu col-12 col-md-4 height-100">
                        <Sidebar title={sideTitle} text={sideText} button={{ title: sideBtnText, url:sideBtnURL }} />
                    </div>
                    <div className="content height-2 col-12 col-md-8">
                        <div className='py-3 d-flex flex-column justify-content-center align-items-center text-light bg-content'>
                            <h1 style={{color: '#7388f5'}} className='my-4'>{heading}</h1>
                            <div className='mt-4 mb-1'>
                                <Logos />
                            </div>
                            <p className='text-grey text-center mx-5'>{subText}</p>
                           {children}
                        </div>
                    </div>

                </div>
            </Content>
        </>
    )
}

