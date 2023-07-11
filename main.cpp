
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget;
    window->setAttribute(Qt::WA_DeleteOnClose);

    // Setup GUI
    QVBoxLayout *topLayout = new QVBoxLayout(window);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    QSpinBox *spinBox = new QSpinBox();
    spinBox->setReadOnly(true);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->addWidget(slider);
    horizontalLayout->addWidget(spinBox);

    topLayout->addLayout(horizontalLayout);

    QObject::connect(slider, &QSlider::valueChanged,
                     spinBox,qOverload<int>(&QSpinBox::setValue));
    slider->setValue(50);

    window->show();
    return a.exec();
}
