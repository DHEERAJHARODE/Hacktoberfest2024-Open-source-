import './style.css';
import { TiSocialFacebook, TiSocialLinkedin } from 'react-icons/ti'
import { IoLogoGoogleplus } from 'react-icons/io'
export default function Logos() {
    return (
        <div className='d-flex'>
            <div className='logo-border'>
                <TiSocialFacebook color='#000' size='30px' />
            </div>
            <div className='logo-border'>
                <IoLogoGoogleplus color='#000' size='30px' />
            </div>
            <div className='logo-border'>
                <TiSocialLinkedin color='#000' size='30px' />
            </div>
        </div>
    )
}